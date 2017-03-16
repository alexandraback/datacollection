def get_slides(B, M):
    mat = [[0 for k in range(B)] for k in range(B)]
    return get_slides_rec(mat, B, M, B)


def get_slides_rec(mat, current, M, B):
    pow2 = 2 ** (current-2)
    if current == 2:
        if M > 1:
            raise ValueError("IMPOSSIBLE")
        mat[0][B-1] = 1
        return mat
    else:
        mat = get_slides_rec(mat, current-1, min(pow2 // 2, M), B)
        #print(mat)
        if M == pow2:
            for k in range(current-2):
                mat[k][current-2] = 1
            mat[current-2][B-1] = 1
        elif M > pow2 / 2:
            k = 1
            N = M % (pow2 // 2)
            mat[current-2][B-1] = 1
            while N != 0:
                mat[current-2][B-1] = 1
                mat[k][current-2] = 1
                N = N // 2
                k += 1
        return mat

if __name__ == "__main__":
    T = int(input())
    for test in range(T):
        line = input().split()
        B = int(line[0])
        M = int(line[1])
        if M > 2 ** (B - 2):
            print("Case #{0}: IMPOSSIBLE".format(test+1))
        else:
            print("Case #{0}: POSSIBLE".format(test+1))
            slides = get_slides(B, M)
            for line in slides:
                row = " ".join([str(s) for s in line])
                print(row)
