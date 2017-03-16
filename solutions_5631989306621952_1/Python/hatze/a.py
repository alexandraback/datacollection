def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        word = ""
        line = raw_input()
        first = line[0]
        word += first
        for c in line[1:]:
            if c >= first:
                word = c + word
                first = c
            else:
                word += c
        print("Case #%i: " % i + word)

if __name__ == "__main__":
    main()
