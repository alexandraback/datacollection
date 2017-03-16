memoized = {}
# seen = {}

def compute(N):
    seen = set([])
    queue = [(1, 1)]
    while queue[0][0] != N:
        if queue[0][0] in seen:
            queue.pop(0)
            continue
        current, steps = queue.pop(0)
        seen.add(current)
        queue.append((current + 1, steps + 1))
        queue.append((int(str(current)[::-1]), steps + 1))
    return queue[0][1]

def compute_pow_10(digits):
    current_digits = 1
    count = 1
    while current_digits < digits - 1:
        count += 2 * ((10 ** ((current_digits + 1) / 2)) - 1)
        count += 1
        current_digits += 1
    return count + 10 ** (digits / 2) - 1

def compute2(N):
    string = str(N)
    digits = len(string)
    count = compute_pow_10(digits)
    first_half = string[:len(string)/2]
    second_half = string[len(string)/2:]

    num = 10 ** (digits - 1)
    str_num = str(num)
    if N == num:
        return count
    if first_half == str_num[:len(string)/2]:
        return count + (N - num)
    if int(second_half) != 0:
        right = int(first_half[::-1])
    else:
        right = int(str(int(first_half) - 1)[::-1])
    if right == int(str_num[:len(str_num)/2][::-1]):
        return count + (N - num)
    count += int(right)
    count += 1
    num = int(str(num + int(right))[::-1])
    count += N - num
    return count


def test_compute2(N):
    c = compute2(N)
    v = compute(N)
    # print c, v
    assert c == v
    return c

input_file = open('a-large.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    N = int(input_file.readline())
    print "Case #{}: {}".format(case, compute2(N))
