import sys

def parse_tests(infile):
    T = int(infile.readline())
    for _ in range(T):
        yield infile.readline().strip()

count_to_digits = { 2: 10 }
for p in range(3, 16):
    half = (p-1) // 2
    val = count_to_digits[p-1] + (10**half - 1) + 1 + (10**(p - half - 1) - 1) 
    count_to_digits[p] = val

def min_steps(N):
    digits = len(N)
    if digits == 1:
        return int(N) 
    c = count_to_digits[digits]
    half = digits // 2 
    first_half = int("".join(reversed(N[:half])))
    second_half = int(N[half:])
    if N[0] == "1" and int(N[1:]) == 0:
        return c
    if second_half > 0:
        first_half_str = N[:half]
    else:
        first_half_str = str(int(N[:half]) - 1)
        
    if int(first_half_str) != 10**(half-1):
        c += int("".join(reversed(first_half_str)))
        c += 1
        c += int(N) - int(first_half_str + "0" * (digits - half - 1) + "1")
    else:
        c += int(N) - int(first_half_str + "0" * (digits - half))
        
    return c

def print_result(case, result):
    print("Case #{}: {}".format(case, result))

def main():
    for case, test in enumerate(parse_tests(sys.stdin), 1):
        result = min_steps(test)
        print_result(case, result)

if __name__ == "__main__":
    main()
