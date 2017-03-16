def solve(data):
    idx = ["Z", "X", "W", "U", "O", "R", "F", "V", "G", "I"]
    digits = ["ZERO",
              "SIX",
              "TWO",
              "FOUR",
              "ONE",
              "THREE",
              "FIVE",
              "SEVEN",
              "EIGHT",
              "NINE"]
    answer = [0, 6, 2, 4, 1, 3, 5, 7, 8, 9]
    result = ""
    for i in xrange(len(idx)):
        c = idx[i]
        count = data.count(c)
        for j in range(count):
            for k in digits[i]:
                c_idx = data.index(k)
                data = data[0:c_idx] + data[c_idx + 1:]
        result += str(answer[i]) * count

    return reduce(lambda a, b: a + b, sorted(result))


def main():
    with open("A-input.in") as fin:
        with open("A-output.out", "w") as fout:
            t = int(fin.readline())
            for i in range(0, t):
                data = fin.readline().strip()
                fout.write("Case #%d: %s\n" % (i + 1, solve(data)))


main()
