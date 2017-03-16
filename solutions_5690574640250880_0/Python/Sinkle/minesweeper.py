import sys
from math import ceil

def check_argv():
	if len(sys.argv) < 3:
		print("USAGE: #python minesweeper.py INPUT_FILE OUTPUT_FILE")
		sys.exit()

def main():
	input_file = sys.argv[1]
	output_file = sys.argv[2]
	print input_file
	print output_file
	with open(input_file, "rb") as input, open(output_file,"w") as output:
		case_count = int(input.readline())
		for case_idx in range(1, case_count+1):
			ret = "Case #"+str(case_idx)+":\n"
			#print ret
			giveup = False
			row_count,col_count,mine_num = map(int, input.readline().split())

			short_edge = min(row_count,col_count)
			long_edge = max(row_count,col_count)

			space_count = row_count*col_count - mine_num
			base_row = min(row_count, int(ceil(space_count**(0.5))))
			base_col = int(ceil(float(space_count)/base_row))
			if base_col > col_count:
				base_col = col_count
				base_row = int(ceil(float(space_count)/base_col))
			bad_mine_num = mine_num - (row_count * col_count - base_row * base_col)

			# build board
			board = []
			for i in range(row_count):
				board.append([])
				for j in range(col_count):
					board[i].append("*")

			for i in range(base_row):
				for j in range(base_col):
					board[i][j]="."

			e1 = base_col
			e2 = base_row
			r = base_row-1
			c = base_col-1

			for bm in range(bad_mine_num):
				if bm == 0:
					board[base_row-1][base_col-1] = "*"
					e1 -= 1
					e2 -= 1
				else:
					if e2 >= e1:
						r -= 1
						e2 -= 1
						board[r][base_col-1] = "*"
					else:
						c -= 1
						e1 -= 1
						board[base_row-1][c] = "*"

			if space_count == 1:
				board[0][0] = "c"
			elif (board[min(1,row_count-1)][base_col-1] == "*" 
					or board[base_row-1][min(1,col_count-1)] == "*"): 
				giveup = True
			else:
				board[0][0] = "c"

			if giveup:
				ret += "Impossible\n"
			else:
				for i in range(row_count):
					ret += ''.join(board[i]) + "\n"
			output.write(ret)

#			for i in range(row_count):
#				print ''.join(board[i])


if __name__ == "__main__":
	main()