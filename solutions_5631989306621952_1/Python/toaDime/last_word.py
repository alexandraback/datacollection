def main_code(x):
    word = input()
    result = word[0]
    for c in word[1:]:
        if c >= result[0]:
            result = c + result
        else:
            result = result + c
    print("Case #" + str(x + 1) + ":", result)

T = int(input())
for x in range(T):
    main_code(x)
