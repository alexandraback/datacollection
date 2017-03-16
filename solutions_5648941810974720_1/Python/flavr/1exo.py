def remove_from(line, number):
    j = 0
    for i, c in enumerate(number):
        j = 0
        while j < len(line):
            if line[j] == c:
                line[j] = None
                j += 1
                break
            j += 1

    return [x for x in line if x is not None]


def hacky_hack(line, output):
    while len(line) > 0:
        # hacky hack
        while True:
            cool_line = set(line)
            if "Z" in cool_line:
                line = remove_from(line, "ZERO")
                output.append(0)
            elif "W" in cool_line:
                line = remove_from(line, "TWO")
                output.append(2)
            elif "X" in cool_line:
                line = remove_from(line, "SIX")
                output.append(6)
            elif "G" in cool_line:
                line = remove_from(line, "EIGHT")
                output.append(8)
            else:
                break

        while True:
            cool_line = set(line)
            if "T" in cool_line:
                line = remove_from(line, "THREE")
                output.append(3)
            elif "S" in cool_line:
                line = remove_from(line, "SEVEN")
                output.append(7)
            else:
                break

        while True:
            cool_line = set(line)
            if "V" in cool_line:
                line = remove_from(line, "FIVE")
                output.append(5)
            else:
                break

        while True:
            cool_line = set(line)
            if "F" in cool_line:
                line = remove_from(line, "FOUR")
                output.append(4)
            elif "I" in cool_line:
                line = remove_from(line, "NINE")
                output.append(9)
            else:
                break

        while True:
            cool_line = set(line)
            if "O" in cool_line:
                line = remove_from(line, "ONE")
                output.append(1)
            else:
                break

    return line


def phone(line):
    output = []
    line = sorted(line)

    hacky_hack(line, output)

    output = sorted(output)
    output = map(str, output)
    return "".join(output)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        line = input()
        print("Case #{}: {}".format(i+1, phone(line)))
