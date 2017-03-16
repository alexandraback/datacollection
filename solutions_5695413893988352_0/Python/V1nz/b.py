from sys import *
from math import *

def solve(case, tab_c, tab_d) :
    superieur = 0
    # -1 >> tab_c superieur
    # 1 >> tab_d superieur
    score_c = ""
    score_d = ""
    i = len(tab_c)
    while i > 0 :
        if superieur == 0 :
            if tab_c[0] == '?' :
                if tab_d[0] == '?' :
                    if i > 1 :
                        if tab_c[1] == '?' or tab_d[1] == '?' :
                            score_c = score_c + '0'
                            score_d = score_d + '0'
                        else :
                            if int(tab_c[1]) - int(tab_d[1]) >= 5 :
                                score_c = score_c + '0'
                                score_d = score_d + '1'
                                superieur = 1
                            else :
                                score_c = score_c + '0'
                                score_d = score_d + '0'
                    else :
                        score_c = score_c + '0'
                        score_d = score_d + '0'
                else :
                    if i > 1 :
                        if tab_c[1] == '?' or tab_d[1] == '?' :
                            score_c = score_c + tab_d[0]
                            score_d = score_d + tab_d[0]
                        else :
                            if int(tab_c[1]) - int(tab_d[1]) >= 5 :
                                score_c = score_c + str(int(tab_d[0])-1)
                                score_d = score_d + tab_d[0]
                                superieur = 1
                            else :
                                score_c = score_c + '0'
                                score_d = score_d + '0'
                    else :
                        score_c = score_c + tab_d[0]
                        score_d = score_d + tab_d[0]
            elif tab_d[0] == '?' :
                if i > 1 :
                    if tab_c[1] == '?' or tab_d[1] == '?' :
                        score_c = score_c + tab_c[0]
                        score_d = score_d + tab_c[0]
                    else :
                        if int(tab_c[1]) - int(tab_d[1]) >= 5 and tab_c[0] != '9':
                            score_c = score_c + tab_c[0]
                            score_d = score_d + str(int(tab_c[0])+1)
                            superieur = 1
                        else :
                            score_c = score_c + tab_c[0]
                            score_d = score_d + tab_c[0]
                else :
                    score_c = score_c + tab_c[0]
                    score_d = score_d + tab_c[0]
            else :
                if int(tab_c[0]) > int(tab_d[0]) :
                    superieur = -1
                elif int(tab_c[0]) < int(tab_d[0]) :
                    superieur = 1
                score_c = score_c + tab_c[0]
                score_d = score_d + tab_d[0]
        elif superieur == -1 :
            if tab_c[0] == '?' :
                score_c = score_c + '0'
            else :
                score_c = score_c + tab_c[0]
            if tab_d[0] == '?' :
                score_d = score_d + '9'
            else :
                score_d = score_d + tab_d[0]
        else :
            if tab_c[0] == '?' :
                score_c = score_c + '9'
            else :
                score_c = score_c + tab_c[0]
            if tab_d[0] == '?' :
                score_d = score_d + '0'
            else :
                score_d = score_d + tab_d[0]
        del tab_c[0]
        del tab_d[0]
        i -= 1
        
    print("Case #{0}: {1} {2}".format(case, score_c, score_d))

cases = int(input())
for i in range(1, cases + 1) :
    ligne = input()
    c, d = ligne.split()
    tab_c = []
    for j in c :
        tab_c.append(j)
    tab_d = []
    for k in d :
        tab_d.append(k)
    solve(i, tab_c, tab_d)
