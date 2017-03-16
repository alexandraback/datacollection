import utils
import itertools


def parse_func(inp_list):
    res = []

    i = 0
    while i < len(inp_list):
        res_set = []
        k, l, s = inp_list[i].split()
        res_set.append((int(k), int(l), int(s)))

        keyboard = [x for x in inp_list[i+1].strip()]
        tgt_word = [x for x in inp_list[i+2].strip()]
        res_set.append(keyboard)
        res_set.append(tgt_word)
        res.append(res_set)
        i += 3
    return res


def get_bananas(tgt_word, word):
    tgt_str = ''.join(tgt_word)
    word_str = ''.join(word)
    f_count = 0
    f_list = []

    i = 0
    while i < len(word_str):
        j = word_str.find(tgt_str, i)
        if j == -1:
            break
        f_list.append(j)
        f_list = list(set(f_list))
        i += 1
    return len(f_list)


def get_exp(b_list):
    avg = float(sum(b_list))/len(b_list)
    return avg


def exec_func(inp_list):
    k, l, s = inp_list[0]
    keyboard = inp_list[1]
    tgt_word = inp_list[2]

    if not set(tgt_word).issubset(set(keyboard)):
        return float(0)

    possibilities = list(itertools.product(keyboard, repeat=s))
    b_list = []

    for p in possibilities:
        b_num = get_bananas(tgt_word, p)
        b_list.append(b_num)
    max_b = max(b_list)
    avg_b = get_exp(b_list)
    return max_b - avg_b


def main():
    utils.main(parse_func, exec_func)


if __name__ == '__main__':
    main()
