def generate_binaries(length):
    for i in range(2 ** (length - 1) + 1, 2 ** length, 2):
        yield str(bin(i))[2:]


def get_divisor(number):
    for i in range(2, int(number ** 0.5)):
        if number % i == 0:
            return i
        # lets not waste so much time on this number
        if i > 1001:
            break
    return None


def is_coin(binary):
    proof = []
    for base in range(2, 11):
        number = int(binary, base=base)
        divisor = get_divisor(number)
        if divisor is None:
            return False, []
        proof.append(divisor)
    return True, proof


def solve_coin(length, count):
    results = []
    for a in generate_binaries(length):
        coin, proof = is_coin(a)
        if coin:
            results.append((a, proof))
        if len(results) == count:
            break
    return results


if __name__ == "__main__":
    input_file = "C-large.in"
    results = []
    with open(input_file, "r") as f:
        first = True
        for line in f:
            if first:
                first = False
            else:
                params = [int(i) for i in line.split()]
                results = solve_coin(params[0], params[1])

    with open("coin_output.txt", "w") as f:
        f.write("Case #1:\n")
        for number, proof in results:
            f.write(number)
            for divisor in proof:
                f.write(" %d" % divisor)
            f.write("\n")
