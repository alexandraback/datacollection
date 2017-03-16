def abc(N, f):
    cnt_num = dict([]);
    for n in range(N*2 - 1):
        num = map(int, f.readline().split(' '));
        for i in num:
            if i in cnt_num:
                cnt_num[i] += 1;
            else:
                cnt_num[i] = 1;
    my_list = [];
    for elem in cnt_num.keys():
        if (cnt_num[elem] % 2 == 1):
            my_list.append(elem);

    return map(str, sorted(my_list));
        
            



if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline());
        for t in range(T):
            N = int(f.readline());

            print "Case #{}: {}".format(t + 1, ' '.join(abc(N, f)))

