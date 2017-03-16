def convert(matrix):
    return '\n'.join(map(lambda line:''.join(map(str, line)), matrix))

def count(matrix):
    def helper(matrix, start, goal, calculated):
        if start in calculated:
            return calculated[start]
        line = matrix[start]
        result = 0
        for i, x in enumerate(line):
            if x:
                result += helper(matrix, i, goal, calculated)
        calculated[start] = result
        return result
    
    return helper(matrix, 0, len(matrix)-1, {len(matrix)-1:1})

    

def generate(N):
    def counter(N):
        for i in xrange(N-1):
            for j in xrange(i+1, N):
                yield(i, j)

    def update(matrix, N):
        for i, j in counter(N):
            if matrix[i][j]:
                matrix[i][j] = 0
            else:
                matrix[i][j] = 1
                return matrix
        else:
            return None
        
    matrix = [[0 for x in xrange(N)] for y in xrange(N)]
    while matrix is not None:
        yield count(matrix), convert(matrix)
        matrix = update(matrix, N)
        
    
outputs = {}
for B in xrange(2, 7):
    for M, matrix in generate(B):
        outputs[(B, M)] = matrix
        
def solve():
    B, M = map(int, raw_input().split(' '))
    if (B, M) in outputs:
        return 'POSSIBLE\n%s' % outputs[(B, M)]
    return 'IMPOSSIBLE'
    
def main():
    T = int(raw_input())
    for i in xrange(T):
        print 'Case', '#%d:' % (i+1,), solve()

if __name__ == '__main__':
    main()
