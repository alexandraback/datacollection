import sys

def read_case(lines):
    n, m = [int(i) for i in lines.next().strip().split()]
    arr = []
    for _ in range(n):
        arr.append([int(i) for i in lines.next().strip().split()])
        assert len(arr[-1]) == m
        
    return arr


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines)))

    return cases


def solve(arr):
    row_max = [max(i) for i in arr]
    transpose = [[arr[i][j] for i in range(len(arr))] for j in range(len(arr[0]))]
    col_max = [max(i) for i in transpose]
    
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] < row_max[i] and arr[i][j] < col_max[j]:
                return 'NO'
    
    return 'YES'
    
            
if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
