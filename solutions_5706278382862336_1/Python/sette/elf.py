import sys

from fractions import gcd


def compute_generations(P, Q):
    generations = 0
    cd = gcd(P, Q)
    P, Q = P / cd, Q / cd
    while P < Q:
        if Q % 2:
            return -1
        Q /= 2
        generations += 1
        if generations > 40:
            return -1
    while Q != 1:
        if Q % 2:
            return -1
        Q /= 2
    return generations


def read_test_case():
    P, Q = sys.stdin.readline().strip().split("/")
    P, Q = int(P), int(Q)
    return P, Q


def format_answer(index, answer):
    if answer > -1:
        return "Case #%d: %d" % (index + 1, answer)
    else:
        return "Case #%d: impossible" % (index + 1,)


def display_results(answers):
    output_lines = []
    for index in range(len(answers)):
        output_line = format_answer(index, answers[index])
        output_lines.append(output_line)
    output = "\n".join(output_lines)
    with open("elf_out.txt", "w") as f:
        print("%s" % output, file=f)


def main():
    line = sys.stdin.readline()
    test_cases = int(line.strip())
    answers = []
    for _ in range(test_cases):
        P, Q = read_test_case()
        generations = compute_generations(P, Q)
        # print(flips)
        answers.append(generations)
    display_results(answers)


if __name__ == "__main__":
    main()
