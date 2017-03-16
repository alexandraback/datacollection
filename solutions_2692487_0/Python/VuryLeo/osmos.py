import sys

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        body, num = tuple(map(int, sys.stdin.readline().split()))
        other = list(map(int, sys.stdin.readline().split()))
        if body == 1:
            ans = num
        else:
            other.sort()
            ans = len(other)
            extra = 0
            for index in range(len(other)):
                while(other[index] >= body):
                    extra = extra + 1
                    body = body + body - 1
                body = body + other[index]
                if extra + len(other) - index - 1 < ans:
                    ans = extra + len(other) - index - 1
        sys.stdout.write("{}\n".format(ans))

