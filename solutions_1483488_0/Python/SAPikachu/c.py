import sys

def get_count_recycled_pairs(number, min, max):
    digits = str(number)
    count = 0
    used_numbers = []
    for i in range(1, len(digits)):
        if digits[i] == "0":
            continue

        new_number = int(digits[i:] + digits[:i])
        if new_number < min or new_number > max:
            continue

        if new_number > number and new_number not in used_numbers:
            used_numbers.append(new_number)
            count += 1

    return count

def solve(input):
    min, max = [int(x) for x in input.split(" ")]
    pairs = 0
    for i in range(min, max + 1):
        pairs += get_count_recycled_pairs(i, min, max)

    return pairs

def run():
    cases = int(sys.stdin.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve(sys.stdin.readline().strip())))

if __name__ == "__main__":
    run()
    # from timeit import Timer
    # 
    # print(Timer(lambda: solve("1000000 2000000")).timeit(1))

