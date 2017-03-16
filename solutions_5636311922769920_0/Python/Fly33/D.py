from sys import stdin, stdout

def solve(test_id):
    print("Case #{}: ".format(test_id), end='')
    K, C, S = (int(x) for x in stdin.readline().split())
    
    if C * S < K:
        print("IMPOSSIBLE")
        return
    
    a = []
    
    i = 0
    while i < K:
        x = 0
        for j in range(C):
            x = x * K + i % K
            i += 1
        a.append(str(x+1))
    
    print(' '.join(a))

def main():
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
