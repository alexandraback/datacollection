def solve_sheep(number):
    digit_set = set()
    if number == 0:
        return "INSOMNIA"

    for i in range(1, 10000):
        current_number = str(i * number)
        for digit in current_number:
            digit_set.add(digit)

        if len(digit_set) >= 10:
            return current_number
    print("possibly im wrong, number was %d" % number)
    return "INSOMNIA"

if __name__ == "__main__":
    results = []
    with open("A-large.in", "r") as f:
        first = True
        for line in f:
            if first:
                first = False
            else:
                number = int(line)
                result = solve_sheep(number)
                results.append(result)

    with open("sheep_output.txt", "w") as f:
        for i, result in enumerate(results):
            f.write("Case #%d: %s\n" % (i + 1, result))
