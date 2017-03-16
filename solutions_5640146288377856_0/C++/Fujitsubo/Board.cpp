#include <Board.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//------------------------------------------------------------------------------
void Board::init()
{
    cin >> mHeight;
    cin >> mWidth;
    cin >> mShipWidth;
    mTurn = 0;
}

//------------------------------------------------------------------------------
void Board::calc()
{
    for (int i = 0; i < mHeight - 1; ++i) {
        mTurn += mWidth / mShipWidth;
    }

    int div = (mWidth / mShipWidth) - 1;
    mTurn += div;
    mTurn += mShipWidth;
    if ((mWidth % mShipWidth) != 0) {
        ++mTurn;
    }
}

//------------------------------------------------------------------------------
void Board::dump() const
{
    
}
