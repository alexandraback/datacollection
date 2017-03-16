T = int(input())


def najdiMax(slovo):
    max_index = 0
    for i in range(0, len(slovo)):
        if (slovo[i] >= slovo[max_index]):
            max_index = i
    return max_index


def vratSlovo(slovo):
    if (len(slovo) <= 0):
        return ''
    max_index = najdiMax(slovo)
    prvy = slovo[:max_index]
    posledny = slovo[max_index+1:]
    return slovo[max_index] + vratSlovo(prvy) + posledny



for tid in range(1, T+1):
    slovo = input()
    vysledok = vratSlovo(slovo)
    print('Case #{}: {}'.format(tid,str(vysledok)))
