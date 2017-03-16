"""Code jam 2015, Qualification Round
Problem B. Infinite House of Pancakes
autor: benfei
"""

def lazy_head_server(Parray):
    Parray = sorted(Parray, reverse=True)
    Pmax = Parray[0]
    abs_min_time = Pmax
    for p in range(Pmax, 0, -1):
        min_time = p
        for i in range(len(Parray)):
            if Parray[i] <= p:
                break
            min_time += (Parray[i] - 1) // p
        if min_time < abs_min_time:
            abs_min_time = min_time
            
    return abs_min_time

def parse_input():
    D = int(input())
    Parray = [int(n) for n in input().split(" ")]
    assert len(Parray) == D, "There must be exactly D non-empty plates"

    return Parray

def print_result(x, y):
    print("Case #{x:d}: {y:d}".format(x=x, y=y))

def main():
    T = int(input())
    for test_case in range(1, T+1):
        Parray = parse_input()
        min_shift_time = lazy_head_server(Parray)
        print_result(test_case, min_shift_time)

if __name__ == "__main__":
    main()