def missing_list(N, lists):
    count_dict = {}
    for lst in lists:
        for num in lst:
            if num in count_dict:
                count_dict[num] += 1
            else:
                count_dict[num] = 1
    odds = []
    for key, val in count_dict.iteritems():
        if val % 2 != 0:
            odds.append(key)
    odds.sort()
    return ' '.join(map(str, odds))

def main():
    f_in = open('B-large.in.txt', 'r')
    f_out = open('B-large.out.txt', 'w')

    n_tests = int(f_in.readline())
    for i in range(n_tests):
        N = int(f_in.readline())
        lists = []
        for j in range(2 * N - 1):
            lst = map(int, f_in.readline().split(' '))
            lists.append(lst)
        f_out.write('Case #{}: {}\n'.format(i + 1, missing_list(N, lists)))

    f_in.close()
    f_out.close()

if __name__ == "__main__":
    main()
