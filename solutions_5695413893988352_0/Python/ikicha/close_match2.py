def solve(a, b):
    (diff, result_a, result_b) = recur(a, b, 0)

    return result_a + " " + result_b


def diff(a, b):
    return abs(int(a) - int(b))


def recur(a, b, who_win):
    a_idx = 20
    if "?" in a:
        a_idx = a.index("?")

    b_idx = 20
    if "?" in b:
        b_idx = b.index("?")
    data = []
    if a_idx == b_idx == 20:
        return diff(a, b), a, b
    if min(a_idx, b_idx) == 0:
        who_win = 0
    elif int(a[:min(a_idx, b_idx)]) > int(b[:min(a_idx, b_idx)]):
        who_win = 1
    elif int(a[:min(a_idx, b_idx)]) < int(b[:min(a_idx, b_idx)]):
        who_win = 2
    elif int(a[:min(a_idx, b_idx)]) == int(b[:min(a_idx, b_idx)]):
        who_win = 0
    if a_idx == b_idx:
        if who_win == 0:
            data.append(recur(insert(a, a_idx, 0), insert(b, b_idx, 0), 0))
            data.append(recur(insert(a, a_idx, 0), insert(b, b_idx, 1), 2))
            data.append(recur(insert(a, a_idx, 1), insert(b, b_idx, 0), 1))
        elif who_win == 1:
            data.append(recur(insert(a, a_idx, 0), insert(b, b_idx, 9), 1))
        elif who_win == 2:
            data.append(recur(insert(a, a_idx, 9), insert(b, b_idx, 0), 2))
    elif a_idx < b_idx:
        if who_win == 0:
            data.append(recur(insert(a, a_idx, b[a_idx]), b, 0))
            int_b = int(b[a_idx])
            if int_b < 9:
                data.append(recur(insert(a, a_idx, int_b + 1), b, 1))
            if int_b > 0:
                data.append(recur(insert(a, a_idx, int_b - 1), b, 2))
        elif who_win == 1:
            data.append(recur(insert(a, a_idx, 0), b, 1))
        elif who_win == 2:
            data.append(recur(insert(a, a_idx, 9), b, 2))
    elif a_idx > b_idx:
        if who_win == 0:
            int_a = int(a[b_idx])
            data.append(recur(a, insert(b, b_idx, int_a), 0))
            if int_a < 9:
                data.append(recur(a, insert(b, b_idx, int_a + 1), 2))
            if int_a > 0:
                data.append(recur(a, insert(b, b_idx, int_a - 1), 1))
        elif who_win == 1:
            data.append(recur(a, insert(b, b_idx, 9), 1))
        elif who_win == 2:
            data.append(recur(a, insert(b, b_idx, 0), 2))

    data.sort(cmp=lambda x, y: x[0] - y[0])
    min_v = data[0][0]
    data = filter(lambda x: x[0] == min_v, data)

    data.sort(cmp=lambda x, y: int(x[1]) - int(y[1]))
    min_v = data[0][1]
    data = filter(lambda x: x[1] == min_v, data)
    print data

    data.sort(cmp=lambda x, y: int(x[2]) - int(y[2]))
    return data[0]


def insert(a, a_idx, value):
    return a[:a_idx] + str(value) + a[a_idx + 1:]


def main():
    with open("B-input.in") as fin:
        with open("B-output.out", "w") as fout:
            t = int(fin.readline())
            for i in range(0, t):
                data = fin.readline().strip()
                fout.write("Case #%d: %s\n" % (i + 1, solve(*data.split())))


main()
