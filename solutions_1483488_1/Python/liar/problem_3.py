def dc(n):
    return len(str(n))

def solve(A, B):
    dcA, dcB = dc(A), dc(B)
    assert(dcA == dcB)
    N = 10 ** (dcA - 1)

    def rotate(n):
        d = n % 10
        return n // 10 + d * N

    from array import array
    checked = array('B', (0 for _ in xrange(B - A + 1)))

    ans = 0
    for i in xrange(B - A + 1):
        n, cnt = A + i, 0
        while not checked[n - A]:
            cnt += 1
            checked[n - A] = 1
            n = rotate(n)
            while n < A or n > B:
                n = rotate(n)
        ans += cnt * (cnt - 1) // 2
    return ans
        

def main():
    N = 0
    with open("problem_3.out", "w") as f:
        for case, line in enumerate(open("problem_3.in", "r")):
            if case == 0:
                N = int(line)
                continue
            elif case > N:
                break
            nums = map(int, line.split(" "))
            A, B = nums
            f.write("Case #{0}: {1}\n".format(case, solve(A, B)))

if __name__ == "__main__":
    main()
