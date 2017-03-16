input = open('B-sample-input.txt', 'r')
output = open('B-sample-output.txt', 'w')

##input = open('B-small-attempt0.in', 'r')
##output = open('B-small.out', 'w')

##input = open('B-large.in', 'r')
##output = open('B-large.out', 'w')


def solve(N, M, lawn):
    row_max = [0] * N
    col_max = [0] * M
    for i in range(N):
        row_max[i] = max(lawn[i])
    for i in range(M):
        col_max[i] = max([lawn[x][i] for x in range(N)])
        for row in range(N):
            for col in range(M):
                val = lawn[row][col]
                if val < row_max[row] and val < col_max[col]:
                        return "NO"
    return "YES"

def main():
    num_cases = int(input.readline().strip())
    for case in range(1, num_cases+1):
        N, M = [int(x) for x in input.readline().split()]
        lawn = []
        for i in range(N):
            lawn.append([int(x) for x in input.readline().split()])
        solution = solve(N, M, lawn)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
