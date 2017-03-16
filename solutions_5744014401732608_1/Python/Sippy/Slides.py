import operator

def find_log(m):
    p = 0
    i = 1
    while True:
        if i * 2 > m:
            break
        i *= 2
        p += 1
    return p, m-i

def find_bin_matrix(x):
    arr = []
    while x>0:
        bit = x%2
        x = x/2
        arr.append(bit)
    return arr

def two_alph(map_alp_num):
    arr = []
    for i in map_alp_num:
        if map_alp_num[i] != 0: arr.append(i)
    return arr


def calc(in_file):
    b, m = map(int, in_file.readline().split())
    if pow(2, b-2) < m:
        return "IMPOSSIBLE"
    ans = "POSSIBLE\n"

    mat = [['0'] * b for _ in range(b)]
    l, rem = find_log(m)
    for i in range(l+2):
        for j in range(i+1, l+2):
          mat[i][j] = '1'
    if(l+1 != b-1):
        mat[l+1][b-1] = '1'

    bit_mat = find_bin_matrix(rem)
    for i in range(len(bit_mat)):
        if bit_mat[i] == 1:
            mat[i+1][b-1] = '1'

    for i in range(b-1):
        ans = ans + "".join(mat[i]) + "\n"
    ans = ans + "".join(mat[b-1])
    return ans


if __name__ == '__main__':
    in_file = open("input.txt")
    ou_file = open("output.txt", 'w')
    T = int(in_file.readline())
    for t in range(T):
        ans = calc(in_file)
        ou_file.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    ou_file.close()
