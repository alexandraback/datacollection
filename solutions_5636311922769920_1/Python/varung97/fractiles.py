import sys, math

def fractiles(K, C, S):
    if S < math.ceil(float(K) / C):
        return 'IMPOSSIBLE'
    else:
        ans = ''
        for start in range(1, K + 1, C):
            curr = start
            i = curr if curr != K else curr - 1
            for j in range(1, C):
                curr = (curr - 1) * K + i + 1
                if i != K - 1:
                    i += 1
            ans += str(curr) + ' '
        return ans[:-1]

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        line = test.readline().strip().split()
        K = int(line[0])
        C = int(line[1])
        S = int(line[2])
        print('Case #' + str(i + 1) + ': ' + str(fractiles(K, C, S)))
