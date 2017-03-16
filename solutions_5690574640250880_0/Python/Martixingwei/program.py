from copy import deepcopy as dcp
from queue import Queue

DIRS = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]

def __generate(row, col, limit_row, limit_col, remaining, r_p, board, all_boards):
        if row>=limit_row:
                if remaining == 0:
                        all_boards.append(dcp(board))
                return
        c_row = row
        c_col = col+1
        if c_col >= limit_col:
                c_col = 0
                c_row += 1
        if row not in [0,limit_row-1] and col == 0:
                c_col = limit_col-1
        if r_p < remaining:
                return
        if r_p > remaining:
                board[row][col] = '.'
                __generate(c_row,c_col,limit_row,limit_col,remaining, r_p-1, board, all_boards)
        if remaining > 0:
                board[row][col] = '*'
                __generate(c_row,c_col,limit_row,limit_col,remaining-1, r_p-1, board, all_boards)

def generate(R,C,M):
        o_R, o_C = R , C
        b_r = 0
        b_c = 0
        flag = True
        while flag:
                flag = False
                if R<C:
                        if M>=R and C>1:
                                flag = True
                                C-=1
                                b_c+=1
                                M-=R
                        # if M>=C and R>1:
                        #         flag = True
                        #         R-=1
                        #         b_r+=1
                        #         M-=C
                if R>=C:
                        if M>=C and R>1:
                                flag = True
                                R-=1
                                b_r+=1
                                M-=C
                        # if M>=R and C>1:
                        #         flag = True
                        #         C-=1
                        #         b_c+=1
                        #         M-=R
        board = [['.' for j in range(C)] for i in range(R)]
        all_boards = []
        __generate(0,0,R,C,M,2*(R+C)-4 if R>=2 and C>=2 else R*C,board,all_boards)
        for i in all_boards:
                c_board = [['*']*o_C]*b_r
                for j in i:
                        c_board.append(['*']*b_c+j)
                yield c_board
        
def board_2_str(board,row,col):
        result = ""
        for i in range(len(board)):
                for j in range(len(board[0])):
                        if i==row and j==col:
                                result+='c'
                        else:
                                result+=board[i][j]
                result+='\n'
        return result[:-1]

def click(board, row, col, limit_row, limit_col):
        board = dcp(board)
        holding = Queue()
        holding.put((row,col))
        count = 0
        while not holding.empty():
                cur_r, cur_c = holding.get()
                if board[cur_r][cur_c] == '.':
                        count += 1
                        board[cur_r][cur_c] = '_'
                        tmp_list = []
                        for dir in DIRS:
                                n_r = cur_r+dir[0]
                                n_c = cur_c+dir[1]
                                if n_r<0 or n_c<0 or n_r>=limit_row or n_c>=limit_col:
                                        continue
                                if board[n_r][n_c]=='*':
                                        break
                                tmp_list.append((n_r,n_c))
                        else:
                                for i in tmp_list:
                                        holding.put(i)
        return count
                
def cal(R,C,M):
        target = R*C-M
        for board in generate(R,C,M):
                for row in range(len(board)):
                        for col in range(len(board[0])):
                                if board[row][col]=='.':
                                        if click(board, row, col, R, C)==target:
                                                return board_2_str(board, row, col)
        return "Impossible"
         

print(cal(5,2,6))

input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
count = 0
for i in range(T):
        para = [int(i) for i in input_file.readline().strip().split(' ')]
        result = cal(*para)
        if result == "Impossible":
                print(i+1, *para)
                count+=1
        output_file.write("Case #{}:\n{}\n".format(i+1, result))
print(count)
