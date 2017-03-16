import sys

def get_line():
    return sys.stdin.readline().strip()

def get_case_prefix(idx):
    return "Case #" + str(idx+1) + ":"

def find_best_time(c, f, x):
    click_rate = 2
    best_time = x / click_rate
    base_time = c / click_rate
    while True:
        click_rate = click_rate + f
        new_time = x / click_rate + base_time
 
        if new_time < best_time:
            best_time = new_time
        else:
            break

        base_time = base_time + c / click_rate

    return best_time

def process_testcase(idx):
    params = map(float, get_line().split())

    result = find_best_time(params[0], params[1], params[2])
    print get_case_prefix(idx), "%.7f" % result

def main():
    num_testcases = int(get_line())
    for idx in range(num_testcases):
        process_testcase(idx)

if __name__ == "__main__":
    main()
