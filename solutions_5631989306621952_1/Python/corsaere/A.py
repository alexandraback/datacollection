INPUT_FILE = "A-large.in"
OUTPUT_FILE = "A-large.out"
with open(INPUT_FILE) as f:
    with open(OUTPUT_FILE, "w") as of:
        cases = int(f.readline())
        i = 1
        for x in f.readlines():
            letters = x
            tWord = []
            for letter in letters:
                if len(tWord) == 0 or letter >= tWord[0]:
                    tWord.insert(0, letter)
                else:
                    tWord.append(letter)
            of.write("Case #{0}: {1}".format(i, "".join(tWord)))
            i = i + 1
