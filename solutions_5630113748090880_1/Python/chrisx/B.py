from collections import Counter

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            N = int(f.readline().split()[0])
            rows = []
            for _ in range(2*N-1):
                rows.append(map(int, f.readline().split()))
            sol = solve(N, rows)
            sol = ' '.join(map(str, sol))
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(N, rows):
    c = Counter()
    for row in rows:
        c.update(row)

    res = []
    for height in c:
        if c[height] % 2 == 1:
            res.append(height)
    assert len(res) == N
    return sorted(res)


dir = "./"

'''
input_file = dir+"B-test.txt"
output_file = dir+"B-test.out.txt"

input_file = dir+"B-small-attempt0.in"
output_file = dir+"B-small-attempt0.txt"

'''
input_file = dir+"B-large.in"
output_file = dir+"B-large.txt"
'''
'''

parse(input_file, output_file)



