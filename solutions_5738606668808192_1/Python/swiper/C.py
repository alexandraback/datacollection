def read_case():
    return map(int, input().split())

def make_solution(n, N):
    h = N//2
    s = format(n, '0' + str(h-1)+'b')
    s = '1' + s
    s = s + "".join('1' if c == '0' else '0' for c in s)
    return [s] + list(range(3, 12))

def solve(case):
    N, J = case
    return [make_solution(i, N) for i in range(2, 2*J+1, 2)]

T = int(input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print("Case #%d:" % (t+1))
    for row in result:
        print(" ".join(map(str, row)))
