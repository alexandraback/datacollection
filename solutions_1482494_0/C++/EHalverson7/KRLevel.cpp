#include "KRLevel.h"

KRLevel::KRLevel()
{

}

KRLevel::KRLevel(int o, int t, int p)
{
    oValue = o ;
    tValue = t ;
    vPos = p ;
    cleared = false ;
    oUsed = false ;
}


void KRLevel::clear()
{
    cleared = true ;
}

void KRLevel::oClear()
{
    oUsed = true ;
}

