import utils
import copy


def parse_func(inp_list):
    res = []

    i = 0
    while i < len(inp_list):
        res_set = []
        c, d, v = inp_list[i].split()
        res_set.append((int(c), int(d), int(v)))

        d_values = inp_list[i+1].split()
        d_values = [int(x) for x in d_values]
        res_set.append(d_values)

        res.append(res_set)
        i += 2

    return res


def possible(v, c, d_values):
    tmp_v = v
    for i in reversed(d_values):
        tmp_c = c
        while tmp_c > 0:
            if i <= tmp_v:
                tmp_v = tmp_v - i
                if tmp_v == 0:
                    return True
            tmp_c = tmp_c - 1
    return False

def exec_func(inp_list):
    c, d, v = inp_list[0]
    d_values = inp_list[1]

    new_set = []
    for i in range(v):
        tgt_val = i + 1
        if not possible(tgt_val, c, d_values):
            new_set.append(tgt_val)
            d_values.append(tgt_val)
            d_values.sort()

    return len(new_set)


def main():
    utils.main(parse_func, exec_func)


if __name__ == '__main__':
    main()
