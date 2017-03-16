from sys import stdin, stdout

def solve(test_id):
    print("Case #{}: ".format(test_id), end='')

    s = stdin.readline().strip()

    n = 0
    for i in range(1, len(s)):
        if s[i-1] != s[i]:
            n += 1
    if s[-1] == '-':
        n += 1

    print("{}".format(n))

def main():
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
