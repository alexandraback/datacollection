"""Code jam 2015, Qualification Round
Problem A. Standing Ovation
autor: benfei
"""

def standing_ovation(Sarray):
    min_inv = 0
    cumsum = 0
    for k, Sk in enumerate(Sarray):
        missings = max(0, k - cumsum)
        min_inv += missings
        cumsum += Sk + missings

    return min_inv

def parse_input(in_str):
    Smax, Sarray = in_str.split(" ")
    Smax = int(Smax)
    assert len(Sarray) == Smax + 1, "Sarray must have exactly Smax + 1 elements"
    Sarray = [int(dig) for dig in Sarray]

    return Sarray

def print_result(test_case, min_inv):
    print("Case #{x:d}: {y:d}".format(x=test_case, y=min_inv))

def main():
    T = int(input())
    for test_case in range(1, T+1):
        in_str = input()
        Sarray = parse_input(in_str)
        min_inv = standing_ovation(Sarray)
        print_result(test_case, min_inv)

if __name__ == "__main__":
    main()