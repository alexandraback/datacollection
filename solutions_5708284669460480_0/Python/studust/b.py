import sys
T = int(sys.stdin.readline())


def main():
    for case in range(1, T + 1):
        res = solve(case)
        sys.stdout.write("Case #{}: {}\n".format(case, res))


def solve(case):
    ins = sys.stdin.readline().split()

    k = int(ins[0])
    l = int(ins[1])
    s = int(ins[2])

    keyboard = sys.stdin.readline()[:-1]
    target = sys.stdin.readline()[:-1]

    keyboard_counts = {}
    for key in keyboard:
        if key not in keyboard_counts:
            keyboard_counts[key] = 0

        keyboard_counts[key] += 1

    for key in keyboard_counts:
        keyboard_counts[key] /= float(k)

    for letter in target:
        if letter not in keyboard:
            return float(0)

    prob_occurence = 1
    for letter in target:
        prob_occurence *= keyboard_counts[letter]

    common = 0
    for i in range(1, len(target)):
        if target[:i] == target[-i:]:
            common = i

    best = (s - common) / (l - common)

    average = prob_occurence * (s - l + 1)

    return best - average

main()
