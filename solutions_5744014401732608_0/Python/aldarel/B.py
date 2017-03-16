import numpy

def matrix_print(matrix, b):
    for i in range(b):
        answer = ""
        for j in range(b):
            if matrix[i][j] < 0.5:
                answer += '0'
            else:
                answer += '1'
        print(answer)

if __name__ == '__main__':
    t = int(input())
    for z in range(1, t+1):
        b, m = [int(s) for s in raw_input().split(" ")]
        max_ways = 1
        prev_max_ways = 1
        deg = 0
        was_found = False
        for k in range(0, b-1):
            if max_ways >= m and (not was_found):
                deg = k
                deg_rest = m - prev_max_ways
                was_found = True
            prev_max_ways = max_ways
            max_ways += (b - 2 - k)
        if max_ways >= m and (not was_found):
            deg_rest = m- prev_max_ways
            deg = b-1
        if max_ways < m:
            print("Case #%d: IMPOSSIBLE" % z)
        else:
            print("Case #%d: POSSIBLE" % z)
            matrix = numpy.zeros((b, b))
            matrix[0][b-1] = 1
            if deg==0:
                matrix_print(matrix, b)
                continue
            deg -= 1
            for i in range(0, deg):
                for j in range(i, b):
                    if i==j:
                        continue
                    matrix[i][j] = 1
                    if j==b-1:
                        continue
                    matrix[j][b-1] = 1
            for j in range(deg+1,deg+1+deg_rest):
                matrix[deg][j] = 1
                if j==b-1:
                    continue
                matrix[j][b-1] = 1
            matrix_print(matrix, b)