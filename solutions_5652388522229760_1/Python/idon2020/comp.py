#10:20

def counting_sheep(N):
    if N == 0:
        return False

    exist_digits = set()
    count = 1
    while count < 10000:
        current_value = count*N
        exist_digits = exist_digits.union(set(str(current_value)))
        if(len(exist_digits) == 10):
            return current_value
        count += 1
    #print 'Loop more than 10000 times'
    return False

def counting_sheep_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        last_count = counting_sheep(int(raw_input()))
        if last_count == False:
            print 'Case #%s: INSOMNIA' % test_case
        else:
            print 'Case #%s: %s' % (test_case, last_count)


counting_sheep_in()