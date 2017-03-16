def winning_last_word(S):
    lst = [S[0]]
    for ch in S[1:]:
        if ord(ch) < ord(lst[0]):
            lst.append(ch)
        else:
            lst.insert(0, ch)
    return ''.join(lst)


def main():
    f_in = open('A-small-attempt0.in.txt', 'r')
    f_out = open('A-small-attempt0.out.txt', 'w')

    n_tests = int(f_in.readline())
    for i in range(n_tests):
        S = f_in.readline()
        f_out.write('Case #{}: {}'.format(i + 1, winning_last_word(S)))

    f_in.close()
    f_out.close()

if __name__ == "__main__":
    main()
