import math

def palindrome(val):    
    val = str(val)
    for i in range(len(val) // 2):
        if val[i] != val[len(val) - i - 1]:
            return False
    return True


def main():
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')

    n = int(fin.readline())
    for case in range(1, n + 1):
        a, b = map(int, fin.readline().split())

        cnt = 0
        while a <= b:
            if palindrome(a):
                root = math.sqrt(a)
                if root == int(root) and palindrome(int(root)):
                    cnt += 1
            a += 1
        print('Case #{}: {}'.format(case, cnt), file=fout)

    fin.close()
    fout.close()

main()
