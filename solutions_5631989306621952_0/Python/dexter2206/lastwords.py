
def get_winning_last_word(S):

    word = S[0]
    for k in range(1, len(S)):
        if S[k] >= word[0]:
            word = S[k] + word
        else:
            word = word + S[k]
    return word

def main():
    T = int(input())
    for k in range(T):
        S = input()
        print("Case #{case}: {word}".format(
            case=k+1, word=get_winning_last_word(S)))

if __name__=="__main__":
    main()
