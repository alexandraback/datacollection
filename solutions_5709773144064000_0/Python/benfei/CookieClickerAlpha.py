__author__ = 'Ben'

from string import Template


def main():
    T = int(input())
    result = ""
    result_line = Template('Case #$n: $res\n')

    for instance in range(1, T + 1):
        input_line = input().split()
        C = float(input_line[0])
        F = float(input_line[1])
        X = float(input_line[2])
        result += result_line.substitute(n=instance, res=get_best_time(C, F, X))

    print(result[:-1], end='')


def get_best_time(C, F, X):
    n = int(X/C-2/F)
    time = X/(2+F*n)
    for k in range(n):
        time += C/(2+F*k)
    return round(time, 7)


if __name__ == "__main__":
    main()