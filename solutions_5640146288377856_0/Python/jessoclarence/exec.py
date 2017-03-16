import utils
import copy


def parse_func(inp_list):
    res = []
    for line in inp_list:
        r, c, w = line.split()
        res.append((int(r), int(c), int(w)))
    return res


def exec_func(inp_tuple):
    r, c, w = inp_tuple
    normal_trials = c/w
    if c%w:
        normal_trials += 1
    normal_trials = normal_trials * r
    normal_trials = normal_trials + w - 1
    return normal_trials


def main():
    utils.main(parse_func, exec_func)


if __name__ == '__main__':
    main()
