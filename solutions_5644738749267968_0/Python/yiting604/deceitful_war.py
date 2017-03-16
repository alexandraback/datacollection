import sys

def get_line():
    return sys.stdin.readline().strip()

def get_case_prefix(idx):
    return "Case #" + str(idx+1) + ":"

def play_war(attacker_list, defender_list):
    a_list = list(attacker_list)
    a_list.sort()
    d_list = list(defender_list)
    d_list.sort()
    points = 0

    while len(a_list) > 0 and len(d_list) > 0:
        if a_list[0] > d_list[0]:
            points = points + 1
            del a_list[0]
            del d_list[0]
        else:
            del a_list[0]

    return points

def process_testcase(idx):
    n = int(get_line())
    naomi_list = map(float, get_line().split())
    ben_list = map(float, get_line().split())

    print get_case_prefix(idx), play_war(naomi_list, ben_list), n - play_war(ben_list, naomi_list)

def main():
    num_testcases = int(get_line())
    for idx in range(num_testcases):
        process_testcase(idx)

if __name__ == "__main__":
    main()
