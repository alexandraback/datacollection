num = input()
for i in range(num):
    numbers = set()
    n = input()
    ans = "INSOMNIA"
    if n != 0:
        new_n = n
        count = 1
        while True:
            temp = new_n
            while True:
                numbers.add(temp % 10)
                temp /= 10
                if temp == 0:
                    break
            if len(numbers) == 10:
                ans = new_n
                break
            new_n += n
    print("Case #" + str(i+1) + ": " + str(ans))
