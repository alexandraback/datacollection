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

def vratSlovo2(slovo):
    prefix = ''
    sufix = ''
    while (len(slovo)> 0):
        max_index = najdiMax(slovo)
        prefix += slovo[max_index]
        sufix = slovo[max_index+1:] + sufix
        slovo = slovo[:max_index]
    return prefix + sufix

for tid in range(1, T+1):
    slovo = input()
    vysledok = vratSlovo2(slovo)
    print('Case #{}: {}'.format(tid,str(vysledok)))
