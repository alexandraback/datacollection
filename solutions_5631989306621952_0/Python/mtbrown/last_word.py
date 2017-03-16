def main():
    cases = int(input())

    for case in range(1, cases + 1):
        str = input()
        print("Case #{0}: {1}".format(case, last_word(str)))


def last_word(str):
    last = ""

    for c in str:
        if last == "":
            last += c
        else:
            if c >= last[0]:
                last = c + last
            else:
                last += c

    return last


if __name__ == "__main__":
    main()