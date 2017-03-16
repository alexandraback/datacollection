def solve_pancake(cakes):
    if "-" not in cakes:
        return 0
    if cakes[-1] == "\n":
        cakes = cakes[:-1]
    current_cakes = cakes[0]
    flip = 0
    for cake in cakes:
        if cake != current_cakes:
            current_cakes = cake
            flip += 1
    if cakes[-1] == "-":
        flip += 1
    return flip


if __name__ == "__main__":
    input_file = "B-large.in"
    results = []
    with open(input_file, "r") as f:
        first = True
        for line in f:
            if first:
                first = False
            else:
                result = solve_pancake(line)
                results.append(result)

    with open("pancake_output.txt", "w") as f:
        for i, result in enumerate(results):
            f.write("Case #%d: %s\n" % (i + 1, result))
