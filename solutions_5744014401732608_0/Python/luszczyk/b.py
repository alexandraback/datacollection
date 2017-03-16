def read_ints():
    return map(int, input().strip().split())


def ones(width, num):
    return "0" * (width - num) + "1" * num


def test_case(b, m):
    max_m = 2 ** (b - 2)
    if m > max_m:
        return None
    elif m == max_m:
        return tuple(ones(b, b - row - 1) for row in range(b))
    else:
        return ("0" + bin(m)[2:].zfill(b - 2) + "0",) + tuple(
            ones(b, b - row - 2) for row in range(b - 1)
        )


assert test_case(2, 2) is None
assert test_case(2, 3) is None
assert test_case(2, 1) == ("01", "00")
assert test_case(3, 2) == ("011", "001", "000")
assert test_case(3, 1) == ("010", "001", "000")
assert test_case(5, 4) == ("01000", "00111", "00011", "00001", "00000")
assert test_case(4, 20) is None


def format_out(t, out):
    if out is None:
        print("Case #{}: IMPOSSIBLE".format(t + 1))
    else:
        print("Case #{}: POSSIBLE".format(t + 1))
        print('\n'.join(out))


def main():
    T, = read_ints()
    for t in range(T):
        b, m = read_ints()
        out = test_case(b, m)
        format_out(t, out)

if __name__ == "__main__":
    main()