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
    return False

def counting_sheep_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        last_count = counting_sheep(int(raw_input()))
        if last_count == False:
            print 'Case #%s: INSOMNIA' % test_case
        else:
            print 'Case #%s: %s' % (test_case, last_count)


def pancakes(S):
    reverse_count = 0
    last_side = S[0]
    for current_side in S[1:]:
        if last_side == current_side:
            continue
        else:
            reverse_count += 1
            last_side = current_side
    if S[-1] == '-':
        reverse_count += 1
    return reverse_count


def pancakes_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        print 'Case #%s: %s' % (test_case, pancakes(raw_input()))


def find_jamcoin(N, J):
    max_trial = int(pow(2, N - 2))
    jamcoin_format = '0%sb'%(N - 2)
    trial = 0
    find_jam_count_count = 0
    answer = {}
    while trial < max_trial and find_jam_count_count < J:
        jamcoin = '1%s1'%format(trial, jamcoin_format)
        result = check_if_jamcoin(jamcoin)
        if result:
            answer[jamcoin] = result
            find_jam_count_count += 1
        trial += 1
    return answer


def check_if_jamcoin(jamcoin):
    divisors = []
    for base in range(2, 11):
        result, divisor = is_prime_possible(int(jamcoin, base))
        if result:
            return False
        else:
            divisors.append(divisor)
    return divisors


up_to_200_prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]
def is_prime_possible(i):
    for divisor in up_to_200_prime:
        if i%divisor == 0:
            return False, divisor
    return True, None


def find_jamcoin_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        N_J = raw_input().split(' ')
        N = int(N_J[0])
        J = int(N_J[1])
        answer = find_jamcoin(N ,J)
        print 'Case #%s:' % test_case
        for sol in answer:
            print sol, ' '.join([str(v) for v in answer[sol]])


def fractiles(K, C, S):
    if K == 1:
        return [1]
    if C == 1:
        if S >= K:
            return range(1, K + 1)
        else:
            return False
    selected_tiles = []
    next_selected_tile = 1
    while next_selected_tile <= K:
        if next_selected_tile == K:
            selected_tiles.append(position_of_tile(K, C, next_selected_tile))
        else:
            selected_tiles.append(position_of_tile(K, C, next_selected_tile) + 1)
        next_selected_tile += 2

    if len(selected_tiles) > S:
        return False
    else:
        return selected_tiles


def position_of_tile(K, C, original_position):
    if original_position == 1:
        return 1
    return (original_position - 1)*int((pow(K, C) - K ))/(K - 1) + original_position

def position_of_tile2(K, C, original_position):
    if original_position == 1:
        return 1
    return (original_position - 1)*(pow(K, C) - K )/(K - 1) + original_position

def position_of_tile3(K, C, original_position):
    if original_position == 1:
        return 1
    v = 0
    for c in range(1, C):
        v += int(pow(K, c))
    return (original_position - 1)*v + original_position



def fractiles_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        KCS = [int(v) for v in raw_input().split(' ')]
        result = fractiles(KCS[0], KCS[1], KCS[2])
        if result:
            print 'Case #%s: %s' % (test_case, ' '.join([str(position) for position in result]))
        else:
            print 'Case #%s: IMPOSSIBLE' % test_case


fractiles_in()
