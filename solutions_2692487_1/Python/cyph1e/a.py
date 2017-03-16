def consume(A, motes):
    while True:
        lo, motes = ([m for m in motes if m < A],
                     [m for m in motes if m >= A])
        A += sum(lo)
        if not lo:
            return A, motes

def test(A, n, motes):
    for _ in range(n):
        A, motes = consume(A, motes)
        A += A - 1

    A, motes = consume(A, motes)
    while motes:
        motes = list(sorted(motes))
        motes.pop()
        A, motes = consume(A, motes)
        n += 1
    return n

def main():
    T = int(input())
    for t in range(T):
        a, n = map(int, input().split())
        motes = [int(x) for x in input().split()]
        res = min([test(a, n, list(motes)) for n in range(50)])
        print("Case #{}: {}".format(t + 1, res))

if __name__ == '__main__':
    main()
