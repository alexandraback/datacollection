def main_code(x):
    N = int(input())
    if N == 0:
        print("Case #" + str(x + 1) + ":", "INSOMNIA")
    else:
        M = N
        seen = set(c for c in str(M))
        while seen != {'0','1','2','3','4','5','6','7','8','9'}:
            M += N
            seen |= set(c for c in str(M))
        print("Case #" + str(x + 1) + ":", M)

T = int(input())
for x in range(T):
    main_code(x)
