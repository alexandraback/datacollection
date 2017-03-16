def solve_fractal(base_length, complexity, students):
    permutations = []
    current_permutation = []
    for i in range(1, base_length + 1):
        current_permutation.append(i)
        if len(current_permutation) == complexity:
            permutations.append(current_permutation)
            current_permutation = []
    if len(current_permutation) > 0:
        while len(current_permutation) < complexity:
            current_permutation.append(1)
        permutations.append(current_permutation)

    if students < len(permutations):
        return ["IMPOSSIBLE"]

    result = []
    for permutation in permutations:
        tile = 1
        for i, section in enumerate(permutation):
            tile += (section - 1) * base_length ** i
        result.append(tile)

    return result


if __name__ == "__main__":
    input_file = "D-small-attempt0.in"
    results = []
    with open(input_file, "r") as f:
        first = True
        for line in f:
            if first:
                first = False
            else:
                params = [int(i) for i in line.split()]
                result = solve_fractal(params[0], params[1], params[2])
                results.append(result)

    with open("fractal_output.txt", "w") as f:
        for i, result in enumerate(results):
            f.write("Case #%d:" % (i + 1))
            for tile in result:
                f.write(" %s" % tile)
            f.write("\n")
