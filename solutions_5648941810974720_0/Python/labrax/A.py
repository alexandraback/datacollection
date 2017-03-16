# python 3

names = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

tests = int(input())

for t in range(1, tests+1):
    word = input()
    amount_c = 0
    amount = {}
    for i in word:
        if i in amount:
            continue
        amount[i] = word.count(i)
        amount_c += word.count(i)
    seq = ['Z', 'X', 'W', 'G', 'T', 'S', 'R', 'V', 'O', 'E']
    seq_n = [0, 6, 2, 8, 3, 7, 4, 5, 1, 9]
    
    count = [0]*10
    
    for i in range(0, len(seq)):
        if amount.get(seq[i]) and amount.get(seq[i]) > 0:
            times = amount.get(seq[i])
            count[seq_n[i]] += times
            rm = names[seq_n[i]]
            for r in rm:
                amount[r] -= times
    output = "Case #{0}: ".format(t)
    for i in range(0, len(count)):
        if count[i] > 0:
            output += str(i)*count[i]
    print(output)
