def main():
    test_cases = int(raw_input())
    for i in range(0, test_cases):
        INITIAL_N = int(raw_input())
        yet_seen = set()
        if INITIAL_N == 0:
            print "Case #"+str(i+1)+": INSOMNIA"
        else:
            yet_seen = yet_seen.union(list(str(INITIAL_N)))
            n = INITIAL_N
            while len(yet_seen) != 10:
                n += INITIAL_N
                yet_seen = yet_seen.union(list(str(n)))
            print "Case #"+str(i+1)+": "+str(n)

if __name__ == "__main__":
    main()
