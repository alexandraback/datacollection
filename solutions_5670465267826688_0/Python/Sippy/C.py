mul = dict()
mul[1] = {1: 1, 'i': 'i', 'j': 'j', 'k': 'k', -1: -1, '-i': '-i', '-j': '-j', '-k': '-k'}
mul['i'] = {1: 'i', 'i': -1, 'j': 'k', 'k': '-j', -1: '-i', '-i': 1, '-j': '-k', '-k': 'j'}
mul['j'] = {1: 'j', 'i': '-k', 'j': -1, 'k': 'i', -1: '-j', '-i': 'k', '-j': 1, '-k': '-i'}
mul['k'] = {1: 'k', 'i': 'j', 'j': '-i', 'k': -1, -1: '-k', '-i': '-j', '-j': 'i', '-k': 1}
mul[-1] = {1: -1, 'i': '-i', 'j': '-j', 'k': '-k', -1: 1, '-i': 'i', '-j': 'j', '-k': 'k'}
mul['-i'] = {1: '-i', 'i': 1, 'j': '-k', 'k': 'j', -1: 'i', '-i': -1, '-j': 'k', '-k': '-j'}
mul['-j'] = {1: '-j', 'i': 'k', 'j': 1, 'k': '-i', -1: 'j', '-i': '-k', '-j': -1, '-k': 'i'}
mul['-k'] = {1: '-k', 'i': '-j', 'j': 'i', 'k': 1, -1: 'k', '-i': 'j', '-j': '-i', '-k': -1}

def cal_remaining(idx, l):
    ans = 1
    for i in range(idx, len(l)):
        ch = l[i]
        ans = mul[ans][ch]
    return ans

def powr(rm_ch, ch, x):
    if x < 0: return "NO"
    r = x%4
    ans = rm_ch
    for _ in range(r):
        ans = mul[ans][ch]
    if 1 == ans: return "YES"
    return "NO"

def cal_ch_exist(ch_exist, idx, cnt, l):
    index = idx
    ans = 1
    for count in range(cnt, cnt + 6):
        for i in range(index, len(l)):
            ch = l[i]
            ans = mul[ans][ch]
            if ch_exist == ans:
                return True, count, i+1
        index = 0
    return False, 0, 0

def calc(file):
    ll, x = map(int, file.readline().split())
    l = list(str(file.readline().split()[0]))
    exist, count, idx = cal_ch_exist('i', 0, 1, l)
    if not exist: return "NO"
    exist, count, idx = cal_ch_exist('j', idx, count, l)
    if not exist: return  "NO"
    exist, count, idx = cal_ch_exist('k', idx, count, l)
    if not exist: return  "NO"
    rm_ch = cal_remaining(idx, l)
    ch = cal_remaining(0, l)
    return powr(rm_ch, ch, x-count)


def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()