def solve(data):
    dict_a = {}
    dict_b = {}

    for a, b in data:
        if a not in dict_a:
            dict_a[a] = 0
        if b not in dict_b:
            dict_b[b] = 0
        dict_a[a] += 1
        dict_b[b] += 1
    fake = 0
    for a, b in data:
        if dict_a[a] == 2 and dict_b[b] == 2:
            fake += 1
    return fake


def main():
    with open("C-input.in") as fin:
        with open("C-output.out", "w") as fout:
            t = int(fin.readline())
            for i in range(0, t):
                n = int(fin.readline())
                data = []
                for j in range(n):
                    data.append(fin.readline().strip().split(" "))
                fout.write("Case #%d: %s\n" % (i + 1, solve(data)))


main()
