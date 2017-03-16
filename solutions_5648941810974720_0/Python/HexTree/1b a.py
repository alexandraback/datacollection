with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            S = f.readline().strip()
            keymap = dict()
            for let in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
                keymap[let] = 0
            for c in S:
                keymap[c] += 1

            counts = dict()
            for i in range(10):
                counts[i] = 0

            while keymap['Z'] > 0:
                counts[0] += 1
                for let in "ZERO":
                    keymap[let] -= 1

            while keymap['X'] > 0:
                counts[6] += 1
                for let in "SIX":
                    keymap[let] -= 1

            while keymap['G'] > 0:
                counts[8] += 1
                for let in "EIGHT":
                    keymap[let] -= 1

            while keymap['U'] > 0:
                counts[4] += 1
                for let in "FOUR":
                    keymap[let] -= 1

            while keymap['F'] > 0:
                counts[5] += 1
                for let in "FIVE":
                    keymap[let] -= 1

            while keymap['V'] > 0:
                counts[7] += 1
                for let in "SEVEN":
                    keymap[let] -= 1

            while keymap['R'] > 0:
                counts[3] += 1
                for let in "THREE":
                    keymap[let] -= 1

            while keymap['T'] > 0:
                counts[2] += 1
                for let in "TWO":
                    keymap[let] -= 1

            while keymap['O'] > 0:
                counts[1] += 1
                for let in "ONE":
                    keymap[let] -= 1

            while keymap['N'] > 0:
                counts[9] += 1
                for let in "NINE":
                    keymap[let] -= 1

            result = ""
            for i in range(10):
                for k in range(counts[i]):
                    result += str(i)

            g.write("Case #%d: %s\n" % ((j + 1), result))