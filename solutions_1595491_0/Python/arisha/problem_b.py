input_file = open('/Users/arisha/Downloads/B-small-attempt0.in')
output_file = open('/Users/arisha/Downloads/B-small-practice.out', 'w')
T = int(input_file.readline())

    
def get_googlers(N, S, p, curr_test):
    count = 0
    surprise = 0
    for i in range(N):
        if p == 0:
            count = N
            continue
        if p == 1:
            if curr_test[i] > 0:
                count += 1
            continue
        if curr_test[i] > (3 * p - 3):
            count += 1
        elif curr_test[i] == (3 * p - 4) or curr_test[i] == (3 * p - 3):
            surprise += 1
    return count, surprise

for i in range(T):
    curr_test = list(map(int, input_file.readline().strip().split(' ')))
    N = curr_test.pop(0)
    S = curr_test.pop(0)
    p = curr_test.pop(0)
    count, surprise = get_googlers(N, S, p, curr_test)
    output_file.write("Case #%d: %d\n" % (i + 1, count + min(S, surprise)))

input_file.close()
output_file.close()
