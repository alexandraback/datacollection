from sys import stdin, stdout

stdin = open('C-small-1-attempt0.in', 'r')
stdout = open('C-small.out', 'w')

T = int(stdin.readline().strip())

for c in range(0, T):

    (R, N, M, K) = [int(x) for x in stdin.readline().strip().split()]

    dic = {}

    for x in range(2, 6):
        for y in range(x, 6):
            for z in range(y,6):
                key = '%d%d%d' % (x, y, z)
                val = {1 : 1}
                val[x] = (val[x] if x in val else 0) + 1
                val[y] = (val[x] if y in val else 0) + 1
                val[z] = (val[x] if z in val else 0) + 1
                val[x*y] = (val[x*y] if x*y in val else 0) + 1
                val[y*z] = (val[y*z] if y*z in val else 0) + 1
                val[z*x] = (val[z*x] if z*x in val else 0) + 1
                val[x*y*z] = (val[x*y*z] if x*y*z in val else 0) + 1
                dic[key] = val

    stdout.write('Case #%d:\n' % (c+1))
    
    for r in range(R):
        ans = {}
        for p in [int(x) for x in stdin.readline().strip().split()]:
            for key in dic:
                ans[key] = (ans[key] if key in ans else 1) * \
                           (dic[key][p] if p in dic[key] else 0)

        result = sorted([(ans[key], key) for key in ans], reverse=True)
        
        stdout.write('%s\n' % result[0][1])


stdin.close()
stdout.close()
