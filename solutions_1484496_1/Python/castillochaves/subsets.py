import sys

def main():
    with sys.stdin as f:
        for x in range(int(f.readline())):
            solve(f, x+1)

def solve(f, case):
    inputs = f.readline().split()
    N = int(inputs[0])
    S = [[int(k)] for k in inputs[1:]]
    subsets = {}
    for s in S:
        subsets[s[0]] = s
#    print subsets
    for i in range(1, N):
        SSn = get_subsets(S, i + 1)
#        print SSn
        for ss in SSn:
            x = sum(ss)
            if x in subsets:
                print "Case #%d:" % case
                print ' '.join([str(n) for n in ss])
                print ' '.join([str(n) for n in subsets[x]])
                return
            else:
                subsets[x] = ss
    print "Case #%d: Impossible" % case 
        
def get_subsets(S, n):
    if n == 1:
        return S
    else:
        subsets = []
        J = S
        for i in range(len(S)):
            J = S[i+1:]
            subsets += [S[i] + x for x in get_subsets(J, n - 1)]
        return subsets

if __name__ == '__main__':
    main()
